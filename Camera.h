#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
public:
	Camera() :
		position_{ VGet(0, 0, 0) },
		target_{ VGet(0, 0, 1) }
	{}

	void Update() override
	{
		SetCameraPositionAndTarget_UpVecY(position_, target_);
	}

	void Draw() override
	{
	}

	~Camera()
	{
	}

private:
	VECTOR position_;
	VECTOR target_;
};
