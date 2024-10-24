#ifndef MATH_H
#define MATH_H
template <typename T>
T vAbs(T x) {//valeur absolue
    return (x < 0) ? -x : x;
}
template <typename T>
void echange(T a,T b) {//swipe
    if (&a != &b) { // Pour éviter de faire un XOR sur la même variable
        T temp = a; 
        a = b;
        b = temp;
    }
}
template <typename T>
T max(T a,T b) {
    return (a > b) ? a : b; 
}
template <typename T>
T min(T a,T b) {
    return (a < b) ? a : b; 
}

struct Vect2 {
    int x, y;
    Vect2(int x = 0, int y = 0) : x(x), y(y) {}
    Vect2 operator+(const Vect2& autre) const noexcept {
        return Vect2{x + autre.x, y + autre.y};
    }
    Vect2 operator-(const Vect2& autre) const noexcept {
        return Vect2{x - autre.x, y - autre.y};
    }
    Vect2 operator*(int scalaire) const noexcept {
        return Vect2{x * scalaire, y * scalaire};
    }
    int static produitVect (const Vect2& a, const Vect2& b) {
        return a.x * b.y - a.y * b.x;
    }
    int static det(Vect2 a,Vect2 b, Vect2 p){
        return(((a.x-p.x)*(b.y-p.y))-((a.y-p.y)*(b.x-p.x)));
    }
};
struct Vect3 : public Vect2 {
    int z;
    Vect3(int x = 0, int y = 0, int z = 0) : Vect2(x, y), z(z) {}
    using Vect2::operator+;
    using Vect2::operator-;
    using Vect2::operator*;
    Vect3 operator+(const Vect3& autre) const noexcept {
        return Vect3{x + autre.x, y + autre.y, z + autre.z};
    }
    Vect3 operator*(int scalaire) const noexcept {
        return Vect3{x * scalaire, y * scalaire, z * scalaire};
    }
};

struct Triangle {
    Vect2 points[3];
    float minX, maxX, minY, maxY;
    Vect3 rgb;

    Triangle(const Vect2& p1, const Vect2& p2, const Vect2& p3,const Vect3 couleur)
        : points{p1, p2, p3}, rgb(couleur)
    {
         minX = min(min(points[0].x, points[1].x),points[2].x);
         maxX = max(max(points[0].x, points[1].x), points[2].x);
         minY = min(min(points[0].y, points[1].y), points[2].y);
         maxY = max(max(points[0].y, points[1].y), points[2].y);
    }
};
// struct Maillage{
//     vector<Triangle> maillage; 
// }
#endif
  