#include "showcolordialog.h"
#include "ui_showcolordialog.h"


ShowColorDialog::ShowColorDialog(DBManager* dbManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowColorDialog), dbManager(dbManager)
{
    ui->setupUi(this);
    if (!dbManager) {
        qDebug() << "Неправильний вказівник DBManager у конструкторі DialogPrintSong";
        // Обробте помилку, можливо, закрийте діалогове вікно або покажіть повідомлення про помилку
        // в залежності від логіки вашого додатка.
        return;
    }
    ui->setupUi(this);

    this->setupModel(TABLE_COLOR ,
                     QStringList() << tr("id")
                                   << tr("color")
                                   << tr("code")
                     );

    model->select();
    this->createUI();

    connect(ui->close, SIGNAL(clicked()), this, SLOT(on_close_clicked()));
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(on_tableView_clicked(const QModelIndex&)));




}



ShowColorDialog::~ShowColorDialog()
{
    delete ui;
}



void ShowColorDialog::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this, dbManager->getDB());
    model->setTable(tableName);

    // Встановлюємо назви стовпців в таблиці із сортуванням даних
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    // Встановлюємо сортування по збільшення даних по нульовому стовпцю
    model->setSort(0, Qt::AscendingOrder);
}

void ShowColorDialog::createUI()
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


void ShowColorDialog::on_close_clicked()
{
    this->close();
}


void ShowColorDialog::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        int selectedRow = index.row();
        Color *selectedColor = getColorFromRow(selectedRow);
        emit chosColor(selectedColor, selectedColor->getID());
    }

}

Color* ShowColorDialog::getColorFromRow(int row) {
    Color *color = new Color();
    color->setID(model->data(model->index(row, 0)).toInt());  // Отримати ID
    color->setName(model->data(model->index(row, 1)).toString());
    color->setCode(model->data(model->index(row, 2)).toString());
    // Ваш код для отримання інших даних колірів
    return color;
}

