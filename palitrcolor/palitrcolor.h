#ifndef PALITRCOLOR_H
#define PALITRCOLOR_H

class PalitrColor {
public:
    PalitrColor() : id(-1), palitr_id(-1), color_id(-1) {}  // Конструктор за замовчуванням

    PalitrColor(int id, int palitr_id, int color_id)
        : id(id), palitr_id(palitr_id), color_id(color_id) {}  // Параметризований конструктор

    // Гетери
    int getId() const { return id; }
    int getPalitrId() const { return palitr_id; }
    int getColorId() const { return color_id; }

    // Сетери
    void setId(int newId) { id = newId; }
    void setPalitrId(int newPalitrId) { palitr_id = newPalitrId; }
    void setColorId(int newColorId) { color_id = newColorId; }

private:
    int id;
    int palitr_id;
    int color_id;
};

#endif // PALITRCOLOR_H
