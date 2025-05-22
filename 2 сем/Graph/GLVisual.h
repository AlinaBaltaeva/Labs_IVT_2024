//#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const float PI = 3.14159265358979323846;
//
//class OutLineCircle : public sf::Drawable
//{
//protected:
//	int R; // ������
//	int q; // ���-�� ������
//	sf::Color col; // ���� �����
//	sf::Vector2f pos; // ��������� ������. ��� ��������� � float x � float y
//public:
//	OutLineCircle(int m_R)
//	{
//		R = m_R;
//		q = 360;
//		col = sf::Color::Black;
//		pos.x = 0;
//		pos.y = 0;
//	}
//	OutLineCircle()
//	{
//		R = 1;
//		q = 360;
//		col = sf::Color::Black;
//		pos.x = 0;
//		pos.y = 0;
//	}
//
//	void setRadius(int m_R)
//	{
//		R = m_R;
//	}
//	void setPointCount(int m_q)
//	{
//		q = m_q;
//	}
//	void setColor(sf::Color color)
//	{
//		col = color;
//	}
//	void setPosition(float m_x, float m_y)
//	{
//		pos.x = m_x;
//		pos.y = m_y;
//	}
//
//	//void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override
//	//{
//	//	vector<sf::Vertex> vertices(q);
//	//	for (int i = 0; i < q; i++)
//	//	{
//	//		sf::Vector2f point_pos(pos.x + cos(i * PI / 180) * R, pos.y + sin(i * PI / 180) * R);
//	//		vertices[i] = sf::Vertex(point_pos, col);
//	//	}
//	//	vertices.push_back(vertices[0]);
//
//	//	target.draw(&vertices[0], q + 1, sf::LinesStrip, states);
//	//}
//
//	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override
//	{
//		// ���������: ������� q + 2 ������ ��� ������������ �����. +2 �����,
//		// ����� �������� ���������� (������ ������� ����� ���������)
//		vector<sf::Vertex> vertices(q + 2); // q + 2 ��� TrianglesFan
//
//		// ����������� ������� (����� �����)
//		vertices[0] = sf::Vertex(pos, col);
//
//		// ��������� ������� - ����� �� ����������
//		for (int i = 0; i < q; i++)
//		{
//			float x = pos.x + cos(i * PI / 180) * R;
//			float y = pos.y + sin(i * PI / 180) * R;
//			vertices[i + 1] = sf::Vertex(sf::Vector2f(x, y), col);
//		}
//
//		// �������� ���� (������ ������� - ���������)
//		vertices[q + 1] = vertices[1];  //  ��������, ����� ��� ���� ����������� ��� ����� �����
//
//		// ������ ���� � ������� sf::TrianglesFan
//		target.draw(&vertices[0], q + 2, sf::TrianglesFan, states); // q + 2 ������, ������ TrianglesFan
//	}
//};