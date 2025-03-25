#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Character
{
protected:
    std::string m_name; // Naam van karakter
    int m_health;       // Aantal levens van karakter
    int m_power;        // Damage van karakter
    int m_healpower;    // Healpower van karakter
public:
    Character(std::string name, int health, int power, int heal) : m_name{name}, m_health{health}, m_power{power}, m_healpower{heal} {}

    virtual void Attack(Character &target)
    {
        std::cout << "\n"
                  << m_name << " attacks " << target.m_name << ".";
        target.m_health -= m_power;
    }

    virtual void Heal()
    {
        std::cout << "\n"
                  << m_name << " uses healing.";
        m_health += m_healpower;
    }

    bool IsAlive() const { return m_health > 0; }

    void ShowStats() const
    {
        std::cout << "\nName: " << m_name << "\tHP: " << m_health;
    }
};

class Enemy : public Character
{
public:
    Enemy(std::string name, int health, int power, int heal) : Character(name, health, power, heal) {}

    void EnemyTurn(Character &target)
    {
        int action = std::rand() % 2;

        if (action == 0)
        {
            Attack(target);
        }
        else
        {
            Heal();
        }
    }
};