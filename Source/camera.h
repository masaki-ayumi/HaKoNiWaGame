#pragma once
#include "../Library/gameObject.h"

/// <summary>
/// �J�����N���X
/// </summary>
class Camera :public GameObject
{
public:
	Camera(SceneBase* scene);
	~Camera();
	void Update();
	void Draw();
	
private:
	VECTOR position;
	VECTOR rotation;
	VECTOR target;	//�J�����̒����_
	
};