#pragma once
#include "../Library/gameObject.h"

class Camera :public GameObject
{
public:
	Camera(SceneBase* scene);
	~Camera();
	void Update();
	void Draw();
	void Yrot(VECTOR add);
	void Zrot(VECTOR add);
	
private:
	VECTOR position;
	VECTOR rotation;
	VECTOR target;
	
	float length= 500.0f;//‰~‰^“®‚Ì”¼Œa(’‹“_‚©‚ç‚Ì‹——£)
};