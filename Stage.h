#pragma once
#include "GameObject.h"

class Stage : public GameObject
{
public:
	Stage() :
		y_{ 10 },
		sizeXZ_{ 100 },
		color_{ 0xaaffaa }
	{
	}
	void Update() override {}
	void Draw() override
	{
		float half{ sizeXZ_ / 2.0f };

		VECTOR v0{ VGet(-half, y_, +half) };
		VECTOR v1{ VGet(+half, y_, +half) };
		VECTOR v2{ VGet(+half, y_, -half) };
		VECTOR v3{ VGet(-half, y_, -half) };
		DrawTriangle3D(v0, v1, v2, color_, TRUE);
		DrawTriangle3D(v0, v3, v2, color_, TRUE);
	}
	~Stage() {}

private:
	float y_;
	float sizeXZ_;
	int color_;
};
