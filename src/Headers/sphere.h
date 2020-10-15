#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public:
    sphere() {}
    sphere(point3 center_in, double radius_in)
        :
        center(center_in),
        radius(radius_in)
    {}

    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& record)
        const override;
public:
    point3 center;
    double radius;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& record) const
{
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b - a * c;

    if (discriminant > 0)
    {
        auto root = sqrt(discriminant);

        auto temp = (-half_b - root) / a;
        if (temp < t_max && temp > t_min)
        {
            record.t = temp;
            record.p = r.at(record.t);
            record.normal = (record.p - center) / radius;
            return true;
        }

        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min)
        {
            record.t = temp;
            record.p = r.at(record.t);
            record.normal = (record.p - center) / radius;
            return true;
        }
    }

    return false;
}

#endif
