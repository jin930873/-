#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<QString>
#include <QMetaType>

class Customer
{
private:
    QString m_name;         // 顾客姓名
    int m_level;            // 顾客等级
    double m_discount;      // 折扣率
    QString m_avatarPath;   // 头像路径

public:
    void display();
    Customer();

    // Getter functions
    QString getName() const { return m_name; }
    int getLevel() const { return m_level; }
    double getDiscount() const { return m_discount; }
    QString getAvatarPath() const { return m_avatarPath; }

    // Setter functions
    void setName(const QString& name) { m_name = name; }
    void setLevel(int level) { m_level = level; }
    void setDiscount(double discount) { m_discount = discount; }
    void setAvatarPath(const QString& path) { m_avatarPath = path; }
    void dispaly();

};

Q_DECLARE_METATYPE(Customer*)

#endif // CUSTOMER_H
