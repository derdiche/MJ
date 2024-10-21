#ifndef ALGO_H
#define ALGO_H
#include "Math.h"
#include <vector>
/*tracer des lignes*/
std::vector<Vect2> bresenham(Vect2 debut,Vect2 fin ) {
    std::vector<Vect2> retour;
    int dx = fin.x - debut.x;
    int dy = fin.y - debut.y;
    int abs_dx = vAbs(dx);
    int abs_dy = vAbs(dy);
    int sx = (dx > 0) ? 1 : -1; // Direction x
    int sy = (dy > 0) ? 1 : -1; // Direction y

    // Dessiner le pixel de départ
    retour.push_back(debut);

    // Application de l'algorithme de Bresenham
    bool swapped = false;
    if (abs_dx < abs_dy) {
        echange(debut.x, debut.y); // Échange si besoin pour simplifier la logique
        echange(abs_dx, abs_dy);
        swapped = true;
    }

    int err = abs_dx / 2;
    for (int i = 0; i < abs_dx; ++i) {
        if (swapped) {
            retour.push_back({debut.y, debut.x}); // Inverser les coordonnées
        } else {
            retour.push_back(debut);
        }

        err -= abs_dy;
        if (err < 0) {
            debut.y += sy;
            err += abs_dx;
        }
        debut.x += sx;
    }
    return retour;
}
std::vector<Vect2> dda(Vect2 debut,Vect2 fin ) { //Digital Differential Analyzer
   std::vector<Vect2> points;
    
    float dx = fin.x - debut.x;
    float dy = fin.y - debut.y;
    int steps = max(vAbs(dx), vAbs(dy));

    // Calcul des incréments
    float x_increment = dx / steps;
    float y_increment = dy / steps;

    float x = debut.x;
    float y = debut.y;

    // Génération des points
    for (int i = 0; i <= steps; i++) {
        points.push_back(Vect2(x, y)); // Ajout du point arrondi
        x += x_increment;
        y += y_increment;
    }

    return points;
}



#endif