#ifndef COLLISION_H
#define COLLISION_H

#include <cmath>
#include <algorithm>

// Substitua isso pelo(s) header(s) da(s) sua(s) classe(s) de geometria criadas no E1

#include "CustomMath.h"
#include "Point.h"
#include "Rect.h"

// Essa é uma implementação do SAT feita pelo Lucas Neves.
// Recebe dois Rects e suas rotações, e detecta se os retângulos colidem.
// Mais informações sobre o método podem ser encontradas nos seguintes links:
// http://www.metanetsoftware.com/technique/tutorialA.html
// http://www.gamedev.net/page/resources/_/technical/game-programming/2d-rotated-rectangle-collision-r2604

class Collision {

    public:
        static inline bool IsColliding(const Rect& a, const Rect& b, float angleOfA, float angleOfB) {
            Point A[] = { Point( a.getX(), a.getY() + a.getH() ),
                          Point( a.getX() + a.getW(), a.getY() + a.getH() ),
                          Point( a.getX() + a.getW(), a.getY() ),
                          Point( a.getX(), a.getY() )
                        };
            Point B[] = { Point( b.getX(), b.getY() + b.getH() ),
                          Point( b.getX() + b.getW(), b.getY() + b.getH() ),
                          Point( b.getX() + b.getW(), b.getY() ),
                          Point( b.getX(), b.getY() )
                        };

            for (auto& v : A) {
                v = Rotate(v - a.getCenter(), CustomMath::degToRad(angleOfA)) + a.getCenter();
            }

            for (auto& v : B) {
                v = Rotate(v - b.getCenter(), CustomMath::degToRad(angleOfB)) + b.getCenter();
            }

            Point axes[] = { Norm(A[0] - A[1]), Norm(A[1] - A[2]), Norm(B[0] - B[1]), Norm(B[1] - B[2]) };

            for (auto& axis : axes) {
                float P[4];

                for (int i = 0; i < 4; ++i) P[i] = Dot(A[i], axis);

                float minA = *std::min_element(P, P + 4);
                float maxA = *std::max_element(P, P + 4);

                for (int i = 0; i < 4; ++i) P[i] = Dot(B[i], axis);

                float minB = *std::min_element(P, P + 4);
                float maxB = *std::max_element(P, P + 4);

                if (maxA < minB || minA > maxB)
                    return false;
            }

            return true;
        }

    private:

        static inline float Mag(const Point& p) {
            return std::sqrt(p.getX() * p.getX() + p.getY() * p.getY());
        }

        static inline Point Norm(const Point& p) {
            return p * (1.f / Mag(p));
        }

        static inline float Dot(const Point& a, const Point& b) {
            return a.getX() * b.getX() + a.getY() * b.getY();
        }

        static inline Point Rotate(const Point& p, float angle) {
            float cs = std::cos(angle), sn = std::sin(angle);
            return Point ( p.getX() * cs - p.getY() * sn, p.getX() * sn + p.getY() * cs );
        }
};


#endif // COLLISION_H
