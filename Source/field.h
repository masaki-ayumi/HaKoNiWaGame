#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// 地形クラス
/// </summary>
class Field : public  GameObject
{
public:
	Field(SceneBase* scene);
	~Field();
	void Update();
	void Draw();

	/// <summary>
	/// 地形と線分の当たり判定
	/// </summary>
	/// <param name="hit">当たった座標を返すポインタ</param>
	/// <param name="from">線分の上限</param>
	/// <param name="to">線分の下限</param>
	/// <returns>当たっていたらtrueを返す</returns>
	bool CollisoinLine(VECTOR *hit, VECTOR from, VECTOR to);

	int hModel;	//地形モデル用ハンドル
	int hSkyModel;	//空モデル用ハンドル
};