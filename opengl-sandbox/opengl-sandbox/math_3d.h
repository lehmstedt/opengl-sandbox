/*
	Copyright 2010 Etay Meiri
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MATH_3D_H
#define	MATH_3D_H

#define M_PI 3.1415
#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)


struct Vector3f
{
	float x;
	float y;
	float z;

	Vector3f()
	{
	}

	Vector3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f Cross(const Vector3f& v) const 
	{
		const float _x = y * v.z - z * v.y;
		const float _y = z * v.x - x * v.z;
		const float _z = x * v.y - y * v.x;

		return Vector3f(_x, _y, _z);
	}

	Vector3f& Normalize()
	{
		const float Length = sqrtf(x * x + y * y + z * z);

		x /= Length;
		y /= Length;
		z /= Length;

		return *this;
	}
};

struct Matrix4f {
	float m[4][4];

	inline Matrix4f operator*(const Matrix4f& Right) const
	{
		Matrix4f Ret;
		for (unsigned int i = 0; i < 4; i++) {
			for (unsigned int j = 0; j < 4; j++) {
				Ret.m[i][j] = m[i][0] * Right.m[0][j] +
					m[i][1] * Right.m[1][j] +
					m[i][2] * Right.m[2][j] +
					m[i][3] * Right.m[3][j];
			}
		}

		return Ret;
	}

	void InitCameraTransform(const Vector3f& Target, const Vector3f& Up)
	{
		Vector3f N = Target;
		N.Normalize();
		Vector3f U = Up;
		U = U.Cross(Target);
		U.Normalize();
		Vector3f V = N.Cross(U);

		m[0][0] = U.x; m[0][1] = U.y; m[0][2] = U.z; m[0][3] = 0.0f;
		m[1][0] = V.x; m[1][1] = V.y; m[1][2] = V.z; m[1][3] = 0.0f;
		m[2][0] = N.x; m[2][1] = N.y; m[2][2] = N.z; m[2][3] = 0.0f;
		m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	}

	void InitScaleTransform(float x, float y, float z) {

		m[0][0] = x;		m[0][1] = 0.0f;		m[0][2] = 0.0f;		m[0][3] = 0.0f;
		m[1][0] = 0.0f;		m[1][1] = y;		m[1][2] = 0.0f;		m[1][3] = 0.0f;
		m[2][0] = 0.0f;		m[2][1] = 0.0f;		m[2][2] = z;		m[2][3] = 0.0f;
		m[3][0] = 0.0f;		m[3][1] = 0.0f;		m[3][2] = 0.0f;		m[3][3] = 1.0f;
	}

	void InitRotateTransform(float x, float y, float z) {
		Matrix4f transX, transY, transZ, rotateTrans;

		InitXRotateTransform(x, transX);
		InitYRotateTransform(y, transY);
		InitZRotateTransform(z, transZ);
		rotateTrans = transZ * transY * transX;

		m[0][0] = rotateTrans.m[0][0];	m[0][1] = rotateTrans.m[0][1];	m[0][2] = rotateTrans.m[0][2];	m[0][3] = rotateTrans.m[0][3];
		m[1][0] = rotateTrans.m[1][0];	m[1][1] = rotateTrans.m[1][1];	m[1][2] = rotateTrans.m[1][2];	m[1][3] = rotateTrans.m[1][3];
		m[2][0] = rotateTrans.m[2][0];	m[2][1] = rotateTrans.m[2][1];	m[2][2] = rotateTrans.m[2][2];	m[2][3] = rotateTrans.m[2][3];
		m[3][0] = rotateTrans.m[3][0];	m[3][1] = rotateTrans.m[3][1];	m[3][2] = rotateTrans.m[3][2];	m[3][3] = rotateTrans.m[3][3];

	}

	void InitXRotateTransform(float x, Matrix4f & trans)
	{
		trans.m[0][0] = 1.0f;	trans.m[0][1] = 0.0f;		trans.m[0][2] = 0.0f;		trans.m[0][3] = 0.0f;
		trans.m[1][0] = 0.0f;	trans.m[1][1] = cosf(x);	trans.m[1][2] = -sinf(x);	trans.m[1][3] = 0.0f;
		trans.m[2][0] = 0.0f;	trans.m[2][1] = sinf(x);	trans.m[2][2] = cosf(x);	trans.m[2][3] = 0.0f;
		trans.m[3][0] = 0.0f;	trans.m[3][1] = 0.0f;		trans.m[3][2] = 0.0f;		trans.m[3][3] = 1.0f;
	}

	void InitYRotateTransform(float y, Matrix4f & trans)
	{
		trans.m[0][0] = cosf(y);	trans.m[0][1] = 0.0f;	trans.m[0][2] = sinf(y);	trans.m[0][3] = 0.0f;
		trans.m[1][0] = 0.0f;		trans.m[1][1] = 1.0f;	trans.m[1][2] = 0.0f;		trans.m[1][3] = 0.0f;
		trans.m[2][0] = -sinf(y);	trans.m[2][1] = 0.0f;	trans.m[2][2] = cosf(y);	trans.m[2][3] = 0.0f;
		trans.m[3][0] = 0.0f;		trans.m[3][1] = 0.0f;	trans.m[3][2] = 0.0f;		trans.m[3][3] = 1.0f;
	}

	void InitZRotateTransform(float z, Matrix4f & trans)
	{
		trans.m[0][0] = cosf(z);	trans.m[0][1] = -sinf(z);	trans.m[0][2] = 0.0f;	trans.m[0][3] = 0.0f;
		trans.m[1][0] = sinf(z);	trans.m[1][1] = cosf(z);	trans.m[1][2] = 0.0f;	trans.m[1][3] = 0.0f;
		trans.m[2][0] = 0.0f;		trans.m[2][1] = 0.0f;		trans.m[2][2] = 1.0f;	trans.m[2][3] = 0.0f;
		trans.m[3][0] = 0.0f;		trans.m[3][1] = 0.0f;		trans.m[3][2] = 0.0f;	trans.m[3][3] = 1.0f;
	}

	void InitTranslationTransform(float x, float y, float z) {
		m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = x;
		m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = y;
		m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = z;
		m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;
	}

	void InitPersProjTransform(float fov, float width, float height, float zNear, float zFar)
	{
		const float ar = width / height;
		const float zRange = zNear - zFar;
		const float tanHalfFOV = tanf(ToRadian(fov / 2.0));

		m[0][0] = 1.0f / (tanHalfFOV * ar);
		m[0][1] = 0.0f;
		m[0][2] = 0.0f;
		m[0][3] = 0.0f;

		m[1][0] = 0.0f;
		m[1][1] = 1.0f / tanHalfFOV;
		m[1][2] = 0.0f;
		m[1][3] = 0.0f;

		m[2][0] = 0.0f;
		m[2][1] = 0.0f;
		m[2][2] = (-zNear - zFar) / zRange;
		m[2][3] = 2.0f * zFar * zNear / zRange;

		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 1.0f;
		m[3][3] = 0.0f;
	}
};


#endif	/* MATH_3D_H */