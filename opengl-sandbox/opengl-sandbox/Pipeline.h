#pragma once

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
	void SetCamera(Vector3f pos, Vector3f target, Vector3f up);
private:
	Vector3f m_scale;
	Vector3f m_worldPos;
	Vector3f m_rotateInfo;
	Matrix4f m_transformation;
	proj_config m_persProj;
	struct {
		Vector3f Pos;
		Vector3f Target;
		Vector3f Up;
	} m_camera;
	
};



