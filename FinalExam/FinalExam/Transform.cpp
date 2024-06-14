#include "Transform.h"
#include <cmath>

namespace Transform
{
	const float PI = 3.14;

	Vertex MoveVertex(Vertex point, Vector meter)
	{
		point.x += meter.x_meter;
		point.y += meter.y_meter;
		return point;
	}

	Vertex RotateVertex(Vertex point, float angle_degree)
	{
		float angle_rad = angle_degree * (PI / 180.0f);
		float cos_theta = cos(angle_rad);
		float sin_theta = sin(angle_rad);

		float x_new = point.x * cos_theta + point.y * sin_theta;
		float y_new = -point.x * sin_theta + point.y * cos_theta;

		point.x = x_new;
		point.y = y_new;
		return point;
	}

	Vertex ScaleVertex(Vertex point, Vector meter)
	{
		point.x *= meter.x_meter;
		point.y *= meter.y_meter;
		return point;
	}
}
