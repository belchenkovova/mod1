#pragma once

#include "engine_gl/namespace.h"

#include "engine_gl/point/point2.h"

template 					<typename type>
class						mod1_engine_gl::point3
{
public :

MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Engine GL, Point3 : Bad index")

	type					x = 0;
	type					y = 0;
	type					z = 0;

							point3() = default;

	explicit				point3(const type &value)
	{
		this->x = value;
		this->y = value;
		this->z = value;
	}

	explicit				point3(const point2<type> &point)
	{
		this->x = point.x;
		this->y = point.y;
		this->z = 0;
	}

							point3(type x, type y, type z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	typedef enum
	{
		convention_xyz,
		convention_xzy
	}						mod1_axis_convention;

	explicit				point3(type *ptr, const mod1_axis_convention &convention)
	{
		if (convention == convention_xyz)
		{
			this->x = ptr[0];
			this->y = ptr[1];
			this->z = ptr[2];
		}
		else if (convention == convention_xzy)
		{
			this->x = ptr[0];
			this->y = ptr[2];
			this->z = ptr[1];
		}
		else
			throw (exception_enum());
	}
							~point3() = default;

	point3<type>			operator + (const point3<type> &other) const
	{
		return (point3<type>(this->x + other.x, this->y + other.y, this->z + other.z));
	}

	point3<type>			operator - (const point3<type> &other) const
	{
		return (point3<type>(this->x - other.x, this->y - other.y, this->z - other.z));
	}

	point3<type>			operator * (const point3<type> &other) const
	{
		return (point3<type>(this->x * other.x, this->y * other.y, this->z * other.z));
	}

	template	 			<typename another_type>
	point3<type>			operator * (const another_type &other) const
	{
		return (point3<type>(this->x * other, this->y * other, this->z * other));
	}

	point3<type>			operator / (const point3<type> &other) const
	{
		return (point3<type>(this->x / other.x, this->y / other.y, this->z / other.z));
	}

	template 				<typename another_type>
	point3<type>			operator / (const another_type &other) const
	{
		return (point3<type>(this->x / other, this->y / other, this->z / other));
	}

	void					operator += (const point3<type> &other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void					operator -= (const point3<type> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	void					operator *= (const point3<type> &other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	template 				<typename another_type>
	void					operator *= (const another_type &other)
	{
		this->x *= other;
		this->y *= other;
		this->z *= other;
	}

	void					operator /= (const point3<type> &other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
	}

	template 				<typename another_type>
	void					operator /= (const another_type &other)
	{
		this->x /= other;
		this->y /= other;
		this->z /= other;
	}

	point3<type>			dot(const point3<type> &other) const
	{
		return (point3<type>(
			this->x * other->x,
			this->y * other->y,
			this->z * other->z));
	}

	static void				dot(const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(
			a->x * b->x,
			a->y * b->y,
			a->z * b->z));
	}

	point3<type>			cross(const point3<type> &other) const
	{
		return (point3<type>(
			this->y * other.z - this->z * other.y,
			this->z * other.x - this->x * other.z,
			this->x * other.y - this->y * other.x));
	}

	static point3<type>		cross(const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
	}

	type					&operator [] (int i)
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			case 2 :
				return (z);
			default :
				throw (exception_index());
		}
	}

	const type				&operator [] (int i) const
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			case 2 :
				return (z);
			default :
				throw (exception_index());
		}
	}


	template 				<typename another_type>
	explicit				operator point3<another_type> () const
	{
		return (point3<another_type>(this->x, this->y, this->z));
	}

	template 				<typename point_like>
	point3<type>			&operator = (const point_like &point)
	{
		this->x = point.x;
		this->y = point.y;
		this->z = 0;
		return (*this);
	}

	bool					operator == (const point3<type> &other)
	{
		if (this->x != other.x)
			return (false);
		if (this->y != other.y)
			return (false);
		if (this->z != other.z)
			return (false);
		return (true);
	}

	bool					operator != (const point3<type> &other)
	{
		return (this->x != other.x and this->y != other.y and this->z != other.z);
	}

	static point3<type>		min(const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(MOD1_MIN(a.x, b.x), MOD1_MIN(a.y, b.y), MOD1_MIN(a.z, b.z)));
	}

	static point3<type>		max(const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(MOD1_MAX(a.x, b.x), MOD1_MAX(a.y, b.y), MOD1_MAX(a.z, b.z)));
	}

	void 					write_to_ptr(type *ptr, const mod1_axis_convention &convention) const
	{
		ptr[0] = this->x;
		if (convention == convention_xyz)
		{
			ptr[1] = this->y;
			ptr[2] = this->z;
		}
		else if (convention == convention_xzy)
		{
			ptr[1] = this->z;
			ptr[2] = this->y;
		}
		else
			throw (exception_enum());
	}

	type					length() const
	{
		return (sqrt(
			this->x * this->x +
			this->y * this->y +
			this->z * this->z));
	}

	void 					normalize()
	{
		type					length = this->length();

		this->x /= length;
		this->y /= length;
		this->z /= length;
	}

	static point3<type>		normalize(const point3<type> &point)
	{
		type				length = point->length();

		return (point3<type>(point->x / length, point->y / length, point->z / length));
	}

	point3<type>			normalized() const
	{
		type				length = this->length();

		return (point3<type>(this->x / length, this->y / length, this->z / length));
	}

	friend std::ostream&	operator << (std::ostream& stream, const point3 &point)
	{
		stream << "(";
		stream << point.x;
		stream << ", ";
		stream << point.y;
		stream << ", ";
		stream << point.z;
		stream << ")";
		return (stream);
	}

	auto					glm() const
	{
		return (glm::vec3(x, y, z));
	}
};
