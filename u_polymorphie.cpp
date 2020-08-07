#include <iostream>
#include <iomanip>
#include <sys/stat.h>
#include <ctime>
#include <vector>

using namespace std;

class GameObject
{
private:
    string _name;
    double _xpos, _ypos;

public:
    GameObject(); //Konstructor
    GameObject(const string &, const double &, const double &);
    virtual void showPosition();
    ~GameObject(); //Destructor
};
GameObject::GameObject(){};
GameObject::GameObject(const string &name, const double &xPos, const double &yPos)
{
    _name = name;
    _xpos = xPos;
    _ypos = yPos;
}
void GameObject::showPosition()
{
    cout << "xPos: " << _xpos << " yPos:" << _ypos << endl;
}
GameObject::~GameObject()
{
    cout << "Gameobject Destructor" << endl;
}

class Player : public GameObject
{
private:
    int _health;
    float _speed;

public:
    Player();
    Player(const string &, const double &, const double &, const int &, const float &);
    void showPosition();
    ~Player();
};
Player::Player(){};
Player::Player(const string &name, const double &xPos, const double &yPos, const int &health, const float &speed) : GameObject(name, xPos, yPos)
{
    _health = health;
    _speed = speed;
}

void Player::showPosition()
{
    GameObject::showPosition();
    cout << "Player Health : " << _health << " Player Speed :  " << _speed << endl;
}
Player::~Player()
{
    cout << "PlayerObject Destructor" << endl;
}

class Enemy : public GameObject
{
private:
    int _health;
    float _speed;

public:
    Enemy();
    Enemy(const string &, const double &, const double &, const int &, const float &);
    void showPosition();
    ~Enemy();
};
Enemy::Enemy(){};
Enemy::Enemy(const string &name, const double &xPos, const double &yPos, const int &health, const float &speed) : GameObject(name, xPos, yPos)
{
    _health = health;
    _speed = speed;
}

void Enemy::showPosition()
{
    GameObject::showPosition();
    cout << "Enemy Health : " << _health << " Enemy Speed :  " << _speed << endl;
}
Enemy::~Enemy()
{
    cout << "EnemyObject Destructor" << endl;
}

int main(int argc, char const *argv[])
{
    Player player{"Giuseppe", 2.5, 2.5, 100, 50};
    Enemy orcs{"Orcs", .5, .5, 200, 2.5};
    vector<GameObject *> gameObjects;
    gameObjects.push_back(&orcs);
    gameObjects.push_back(&player);

    for(GameObject *go:gameObjects){
        (*go).showPosition();
    }


    return 0;
}