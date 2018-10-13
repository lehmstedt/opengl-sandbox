#pragma once

#define M_PI 3.1415
#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)


struct proj_config {
	float Width;
	float Height;
	float zNear;
	float zFar;
	float FOV;
};


class Pipeline
{
public:
	Pipeline();
	const Matrix4f * GetTrans();
	void Scale(float ScaleX, float ScaleY, float ScaleZ);
	void WorldPos(float x, float y, float z);
	void Rotate(float RotateX, float RotateY, float RotateZ);
	void SetPerspectiveProj(float zNear, float width, float height, float fov, float zFar);
private:
	void InitScaleTransform(Matrix4f & trans);
	void InitRotateTransform(Matrix4f & trans);
	void InitXRotateTransform(Matrix4f & trans);
	void InitYRotateTransform(Matrix4f & trans);
	void InitZRotateTransform(Matrix4f & trans);
	void InitTranslationTransform(Matrix4f & trans);
	void InitPerspectiveProj(Matrix4f & trans) const;
	Vector3f m_scale;
	Vector3f m_worldPos;
	Vector3f m_rotateInfo;
	Matrix4f m_transformation;
	proj_config m_persProj;
	
	
};



