#include "HeaderFile/object.h"

void Object::resetPosition() {
	position = 10;
}
int Object::getPosition() {
	if (this != nullptr)
		return position;
}
int Object::getW() {
	return w;
}
void Object::moveLeft() {
	--position;
	if (position < w)
		position = w;
}
void Object::moveRight() {
	++position;
	if (position > MAXLENGHT - 2)
		position = MAXLENGHT - 2;
}
void Player::draw(int row) {
	Draw drawer;
	drawer.drawHuman(getPosition(), row + 3);
}
bool Player::isImpact(mObject &obj) {
	if (abs(obj.getPosition() - position) < obj.getW() + getW()) return true;
	return false;
}
void Player::moveForward() {
	--lane;
}
void Truck ::draw(int row) {
	Draw drawer;
	drawer.drawTruck(getPosition(), row + 3, direct);
}
void Car::draw(int row) {
	Draw drawer;
	drawer.drawCar(getPosition(), row +3, direct);
}
void Bird::draw(int row) {
	Draw drawer;
	drawer.drawBird(getPosition(), row + 1, direct);
}
void Dino::draw(int row){
	Draw drawer;
	drawer.drawDino(getPosition(), row);
}
void mObject::moveLeft() {
	--position;
	if (position < getW())
		position = MAXLENGHT - getW();
}
void mObject::moveRight() {
	position++;
	if (position > MAXLENGHT - getW())
		position = getW();
}
void  Player::setLane(int lane) {
	this->lane = lane;
}
int  Player::getLane() {
	return lane;
}
void Player::drawInfo(int column, int row,Color color1, Color color2) {
	Draw a;
	a.cursorPosition(column, row);
	a.setTextColor(color1);
	cout << "Name: " ;
	a.cursorPosition(column, row + 3);
	cout << "Highest Level:";
	a.setTextColor(color2);
	a.cursorPosition(column, row +1);
	cout << pName.substr(0,15);
	a.cursorPosition(column, row+4); 
	cout << highestlevel + 1;
}
void Player::record(int level) {
	if (level > highestlevel) highestlevel = level;
}
void Player::drawEffect(int row) {
	Draw a;
	a.drawEffect(position, row);
}
int Player::getHigestLevel() {
	return highestlevel;
}
string Player::getName() {
	return pName;
}