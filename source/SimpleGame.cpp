/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "ObjectManager.h"
#include "Sound.h"
#include "EndScene.h"
#include <ctime>

int elapsedTime{};
extern float deltatime;
extern InputManager input;

void RenderScene(int temp){
	deltatime = float(glutGet(GLUT_ELAPSED_TIME) - elapsedTime) / 1000.0f;
	D_SCENE->update(deltatime);
	D_SCENE->draw();
	glutSwapBuffers();
	elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	glutTimerFunc(16, RenderScene, 16);
}

void Idle(void){
	
}

void MouseInput(int button, int state, int x, int y){
	input.setMouseInfo(button, x, y);
}
void Motion(int x, int y) {
	input.setMouseInfo(x, y);
}
int main(int argc, char **argv)
{
	srand(time(NULL));
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1024, 600);
	glutCreateWindow("Game Software Engineering KPU");
	
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
		std::cout << " GLEW Version is 3.0\n ";
	else
		std::cout << "GLEW 3.0 not supported\n ";
	
	glutDisplayFunc(Idle);
	glutMouseFunc(MouseInput);
	glutMotionFunc(Motion);
	elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	D_SCENE->commit(new MenuScene, "Menu");
	D_SCENE->commit(new GameScene, "Game");
	D_SCENE->commit(new EndScene, "End");
	Sound::instance().CreateBGSound("Resources/backgroundsound.mp3");
	Sound::instance().CreateShortSound("Resources/swipeeffect1.wav");
	Sound::instance().CreateShortSound("Resources/swipeeffect2.wav");
	Sound::instance().CreateShortSound("Resources/swipeeffect3.wav");
	Sound::instance().CreateShortSound("Resources/swipeeffect4.wav");
	Sound::instance().CreateShortSound("Resources/diesound.wav");
	glutTimerFunc(16, RenderScene, 16);

	glutMainLoop();
	printf("EXIT");
    return 0;
}

