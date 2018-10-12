#pragma once

#define M_PI 3.1415
#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

class Pipeline
{
public:
	Pipeline();
	const Matrix4f * GetTrans();
	void Scale(float ScaleX, float ScaleY, float ScaleZ);
	void WorldPos(float x, float y, float z);
	void Rotate(float RotateX, float RotateY, float RotateZ);
private:
	void InitScaleTransform(Matrix4f & trans);
	void InitRotateTransform(Matrix4f & trans);
	void InitTranslationTransform(Matrix4f & trans);
	Vector3f m_scale;
	Vector3f m_worldPos;
	Vector3f m_rotateInfo;
	Matrix4f m_transformation;
};

