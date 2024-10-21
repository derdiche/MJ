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
    float x, y;
    Vect2(float x = 0, float y = 0) : x(x), y(y) {}
    Vect2 operator+(const Vect2& autre) const noexcept {
        return Vect2{x + autre.x, y + autre.y};
    }
    Vect2 operator-(const Vect2& autre) const noexcept {
        return Vect2{x - autre.x, y - autre.y};
    }
    Vect2 operator*(float scalaire) const noexcept {
        return Vect2{x * scalaire, y * scalaire};
    }
};
struct Vect3 : public Vect2 {
    float z;
    Vect3(float x = 0, float y = 0, float z = 0) : Vect2(x, y), z(z) {}
    using Vect2::operator+;
    using Vect2::operator-;
    using Vect2::operator*;
    Vect3 operator+(const Vect3& autre) const noexcept {
        return Vect3{x + autre.x, y + autre.y, z + autre.z};
    }
    Vect3 operator-(const Vect3& autre) const noexcept {
        return Vect3{x - autre.x, y - autre.y, z - autre.z};
    }
    Vect3 operator*(float scalaire) const noexcept {
        return Vect3{x * scalaire, y * scalaire, z * scalaire};
    }
};
struct Triangle {
    Vect3 points[3];
};
// struct Maillage{
//     vector<Triangle> maillage; 
// }
#endif