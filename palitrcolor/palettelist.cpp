#include "palettelist.h"
#include "ui_palettelist.h"

PaletteList::PaletteList(DBManager* dbManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PaletteList), dbManager(dbManager)
{
    if (!dbManager) {
        qDebug() << "Неправильний вказівник DBManager у конструкторі DialogPrintSong";
        // Обробте помилку, можливо, закрийте діалогове вікно або покажіть повідомлення про помилку
        // в залежності від логіки вашого додатка.
        return;
    }

    ui->setupUi(this);

    this->setupModel(TABLE_PALITR ,
                     QStringList() << tr("id")
                                   << tr("name")
                                   << tr("user_id")
                     );

    model->select();
    this->createUI();
}

PaletteList::~PaletteList()
{
    delete ui;
}

void PaletteList::on_login(User *user)
{
    if (current_user) {
        delete current_user;
    }
    current_user = new User(*user);

    this->setupModel(TABLE_PALITR ,
                     QStringList() << tr("id")
                                   << tr("name")
                                   << tr("user_id")
                     );

    model->select();
    this->createUI();
}


void PaletteList::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this, dbManager->getDB());
    model->setTable(tableName);

    // Встановлюємо назви стовпців в таблиці із сортуванням даних
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }

    // Встановлюємо сортування по збільшенню даних по нульовому стовпцю
    model->setSort(0, Qt::AscendingOrder);

    // Додаємо фільтр, щоб показувати лише рядки з поточним користувачем
    if (current_user) {
        qDebug() << current_user->getID();
        QString filter = QString("user_id = %1").arg(current_user->getID());
        model->setFilter(filter);
    }
    // Оновлюємо модель
    model->select();
}


void PaletteList::createUI()
{
    ui->tableView->setModel(model);     // Встановлюємо модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Приховуємо колонку з  id записів таблиці БД
    // Дозволяємо виділення рядків
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Встановлюємо режим виділення лише одного рядка в таблиці
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Встановлюємо розмір колонок по вмісту
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}



void PaletteList::on_close_clicked()
{
    this->close();
}


void PaletteList::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        try {
            qDebug() << "click";

            // Отримуємо значення з вибраного рядка
            int id = model->data(model->index(index.row(), 0)).toInt();
            QString name = model->data(model->index(index.row(), 1)).toString();
            int userId = model->data(model->index(index.row(), 2)).toInt();

            qDebug() << "step 1";

            // Отримуємо користувача, який є власником цієї палітри
            User* owner = dbManager->getUserById(userId);

            qDebug() << "get user";

            // Створюємо об'єкт палітри
            selectedPalitr = new Palitr(name, owner);
            selectedPalitr->setID(id);

            qDebug() << "palitr created";

            // Отримуємо масив color_id за palitr_id
            QVector<int> colorIds = dbManager->getColorIdsByPalitrId(id);

            qDebug() << "маємо масив";
            qDebug() << selectedPalitr->getID();
            qDebug() << selectedPalitr->getName();
            qDebug() << selectedPalitr->getUser()->getLogin();

            // Заповнюємо палітру кольорами
            for (int i = 0; i < qMin(colorIds.size(), 4); ++i) {
                // Отримуємо об'єкт Color за його ідентифікатором
                Color* color = dbManager->getColorById(colorIds[i]);

                qDebug() << "колір отримано";

                // Перевіряємо, чи отримали ми дійсний колір
                if (color) {
                    // Додаємо колір до палітри
                    selectedPalitr->putColor(i, color);

                    qDebug() << selectedPalitr->getColor(i).colorToString();
                } else {
                    qDebug() << "Не вдалося отримати колір за ідентифікатором " << colorIds[i];
                }
            }

            qDebug() << "сигнал відправлено";

            // Відправляємо сигнал із вибраною палітрою
            emit palitrSelected(selectedPalitr);
        } catch (const std::exception &e) {
            qDebug() << "Виняток під час обробки події: " << e.what();
        } catch (...) {
            qDebug() << "Невідомий виняток під час обробки події";
        }
    }
}

