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

/*triangle plein*/
std::vector<Vect2> Bresenham( Triangle t){
    std::vector<Vect2> points;
    int x1 =t.points[0].x;
    int y1 = t.points[0].y;
    int x2 = t.points[1].x;;
    int y2 = t.points[1].y;;
    
    int dx = vAbs(x2 - x1);
    int dy = vAbs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        points.emplace_back(static_cast<float>(x1), static_cast<float>(y1));

        if (x1 == x2 && y1 == y2) break;
        int err2 = err * 2;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    return points;
}

// std::vector<Vect2> remplissageZone( Triangle t){}
bool estDansTriangle(Triangle t, Vect2 p){
    //produit vectoriel,(barycentrique moins adapté meme si les 2 ont une complexité  O(1))
    // Points du triangle
    Vect2 A = t.points[0];
    Vect2 B = t.points[1];
    Vect2 C = t.points[2];

    // Calcul des vecteurs
    Vect2 AP = p - A;
    Vect2 AB = B - A;
    Vect2 AC = C - A;
    Vect2 BC = C - B;

    // Calcul des produits vectoriels
    float cross1 = Vect2::produitVect(AB, AP); // AB x AP
    float cross2 = Vect2::produitVect(AC , AP); // AC x AP
    float cross3 = Vect2::produitVect(BC, (p - B)); // BC x BP

    // Vérification des signes des produits vectoriels
    return (cross1 >= 0 && cross2 >= 0 && cross3 >= 0) || 
           (cross1 <= 0 && cross2 <= 0 && cross3 <= 0);
}
bool isInside(Triangle t, Vect2 p){
    Vect2 V1=t.points[0];
    Vect2 V2=t.points[1];
    Vect2 V3=t.points[2];
    return  Vect2::det(V3,V1,p)>0 &&
            Vect2::det(V1,V2,p)>0 &&
            Vect2::det(V2,V3,p)>0 ||
            Vect2::det(V3,V1,p)<0 &&
            Vect2::det(V1,V2,p)<0 &&
            Vect2::det(V2,V3,p)<0;
}


#endif