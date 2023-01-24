#pragma once

#include <cmath>
#include <iostream>
#include <ostream>

class vec3 {
    public:
        vec3();
        vec3(double, double, double);
        
        double x() const; // get x
        double y() const; // get y
        double z() const; // get z

        vec3 operator-() const; // get opposite number
        double operator[](int) const; // get by index
        double& operator[](int); // get address by index

        vec3& operator+=(const vec3&); // += operation
        vec3& operator*=(const double); // *= operation
        vec3& operator/=(const double); // /= operation

        double length() const;

    private:
        double length_squared() const;
        double e[3];

    // vec3 Utility Functions
    // friend 
    public:
        friend inline std::ostream& operator<<(std::ostream&, const vec3&);

        friend inline vec3 operator+(const vec3&, const vec3&);
        friend inline vec3 operator-(const vec3&, const vec3&); 
        friend inline vec3 operator*(const vec3&, const vec3&);
        friend inline vec3 operator*(double, const vec3&);
        friend inline vec3 operator*(const vec3&, double);
        friend inline vec3 operator/(vec3&, double);

        friend inline double dot(const vec3&, const vec3&);
        friend inline vec3 cross(const vec3&, const vec3&);
        friend inline vec3 unit_vector(vec3);

};

using point3 = vec3;
using color = vec3;
