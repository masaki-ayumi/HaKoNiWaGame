#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// �n�`�N���X
/// </summary>
class Field : public  GameObject
{
public:
	Field(SceneBase* scene);
	~Field();
	void Update();
	void Draw();

	/// <summary>
	/// �n�`�Ɛ����̓����蔻��
	/// </summary>
	/// <param name="hit">�����������W��Ԃ��|�C���^</param>
	/// <param name="from">�����̏��</param>
	/// <param name="to">�����̉���</param>
	/// <returns>�������Ă�����true��Ԃ�</returns>
	bool CollisoinLine(VECTOR *hit, VECTOR from, VECTOR to);

	/// <summary>
	/// �n�`�Ƌ��̂̓����蔻��
	/// </summary>
	/// <param name="hit">�����������̍��W�Ԃ��|�C���^</param>
	/// <param name="position">�v���C���[�̍��W</param>
	/// <returns>�������Ă�����true��Ԃ�</returns>
	bool CollisoinSphere(VECTOR *hit, VECTOR position);

	int hModel;	//�n�`���f���p�n���h��
	int hSkyModel;	//�󃂃f���p�n���h��
	VECTOR position;
};