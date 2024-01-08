#ifndef PALITRCOLOR_H
#define PALITRCOLOR_H

class PalitrColor {
public:
    PalitrColor();

    PalitrColor(int id, int palitr_id, int color_id);

    int getId() const;
    int getPalitrId() const;
    int getColorId() const;

    void setId(int newId);
    void setPalitrId(int newPalitrId);
    void setColorId(int newColorId);

private:
    int id;
    int palitr_id;
    int color_id;
};

#endif // PALITRCOLOR_H
