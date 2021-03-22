/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** macros
*/

#define CVECTOR(X, Y) (X.x == Y.x && X.y == Y.y)
#define SVECTOR(X, Y) X.x = Y.x; \
X.y = Y.y;
#define NVECTOR(V, X, Y) V.x = X; \
V.y = Y;
#define AVECTOR(V, X, Y) V.x += X; \
V.y += Y;
#define P_MOV(W, X, Y, Z) W = X;   \
Y += Z;
#define RVECTOR(X, Y, R) ((Y.x <= X.x + R && Y.x >= X.x - R) \
&& (Y.y <= X.y + R && Y.y >= X.y - R))
#define VLEN(U) (sqrtf(powf(U.x, 2) + powf(U.y, 2)))
#define SCALAR(U, V) (U.x * V.x + U.y * V.y)
#define GVECTOR(V, X, Y) V.x = Y.x - X.x; \
V.y = Y.y - X.y;
#define CVECTOR3(X, Y) (X.x == Y.x && X.y == Y.y && X.z == Y.z)
#define NVEC3(V, X, Y, Z) V.x = X; \
V.y = Y; \
V.z = Z;
#define CLEARFILE(X) fclose(fopen(X, "w"));
