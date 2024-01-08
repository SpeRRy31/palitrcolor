#include "palitrcolor.h"

PalitrColor::PalitrColor() : id(-1), palitr_id(-1), color_id(-1) {}  

PalitrColor::PalitrColor(int id, int palitr_id, int color_id)
    : id(id), palitr_id(palitr_id), color_id(color_id) {}  

int PalitrColor::getId() const { return id; }
int PalitrColor::getPalitrId() const { return palitr_id; }
int PalitrColor::getColorId() const { return color_id; }

void PalitrColor::setId(int newId) { id = newId; }
void PalitrColor::setPalitrId(int newPalitrId) { palitr_id = newPalitrId; }
void PalitrColor::setColorId(int newColorId) { color_id = newColorId; }
