#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QTableWidget>
#include <QComboBox>
#include <QDebug>
#include "Customer.h"
#include "Cuisine.h"
#include "order.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    // 菜品营收和销售历史统计
    QMap<QString, double> m_dishRevenue;
    QMap<QString, QList<QPair<QDateTime, int>>> m_dishSalesHistory;

    // 原始订单列表
    QVector<Order> m_originalOrders;

    // 菜品统计方法
    void calculateDishRevenue();
    void calculateCategoryStatistics();
    void displayCategoryStatistics();

    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    // 当前选中的顾客
    Customer* m_selectCustomer;

    // 键盘操作
    void keyPressEvent(QKeyEvent *event) override;

    // 数据加载方法
    void loadData(const QString &filename);
    void loadaccount(const QString &filename);
    void writeorder(const QString &filename); // 加载订单数据

    // 订单管理
    Order m_currentOrder;
    double m_orderTotalPrice;
    void ordercuisine();
    void initializeOrderTable();
    void displayOrders();
    QVector<Order> order; // 当前订单列表

    // 订单摘要显示
    void displayOrderSummary();

    // 顾客等级变化处理
    void onCustomerLevelChanged(int index);
    void saveCustomerData();

    // 订单状态变化处理
    void onOrderStatusChanged(int index);

    // 菜品销售统计
    QMap<QString, int> dishSalesMap;
    QMap<QString, int> m_dishSales; // 菜品销量统计

    // 销售统计方法
    void calculateTodaySales();
    void displaySalesStatistics();

    // 搜索功能
    void searchByCustomer(const QString &customerName);
    void performSearch();

    // 菜品销量统计
    void calculateTotalDishSales();
    void saveOrdersToFile();
    void displayCategoryStatistics(const QMap<QString, int> &sales, const QMap<QString, double> &revenue);

    // 菜品查找
    Cuisine *findDishByName(const QString &name);
    void calculateDishSales();

    // 订单文件操作
    bool clearOrderFile();

    // 新增：从指定订单列表统计销量
    void calculateDishSalesFrom(const QVector<Order> &orders);
    double validateDiscountRate(double rate);
    double validateDiscountPrice(double price, double originalPrice);
    void sortCuisinesByDiscountPrice();
    void showHelpOnTextEdit2();
private slots:
    // 表格数据变化处理
    void onTableDataChanged(int row, int column);

    // 菜单按钮
    void on_muneB_released();
    void saveToFile();
    void on_addButton_released();
    void on_saveButton_released();
    void on_saleButton_released();
    void on_classifyButton_released();

    // 账户管理
    void on_accountma_released();

    // 订单管理
    void on_ordermanage_released();
    void on_createorderButton_released();

    // 表格点击处理
    void on_tableWidget_cellClicked(int row, int column);
    void on_dishPagetableWudget_cellClicked(int row, int column);

    // 创建订单
    void on_overorderButton_released();

    // 订单详情
    void on_DATAdetailButton_released();
    void on_saveaccountButton_released();

    // 统计功能
    void on_staticButton_released();
    void on_detailorderButton_clicked();

    // 搜索功能
    void on_searchButton_released();
    void on_backButton_released();

    // 页面导航
    void on_pushButton_6_released();
    void on_statisticsButton_released();


    // 优惠按钮
    void on_saleButton_clicked(bool checked);
    void on_pushButton_7_released();



    void on_paixu_2_released();

private:
    // UI和数据结构
    Ui::MainWidget *ui;
    QStringList m_fields;
    QStringList m_fields1;
    QList<Cuisine*> m_cuisine;

    // 订单管理
    QList<Order> m_allOrders;
    bool m_isSearching = false;

    // 菜品分类
    QMap<QString, QList<Cuisine*>> groupCuisinesByType();

    // 顾客管理
    QList<Customer*> m_customer;
    QList<Order*> m_order;
    QStringList m_fields2;
    QList<Customer*> m_selectedCustomer;

    // 当前选择的菜品
    QMap<Cuisine*, int> m_map;
    QStringList m_fields3;

    // 搜索模式标记
    bool m_isSearchMode = false;
    QList<Order*> m_Order;

protected:
    // 窗口关闭事件
    void closeEvent(QCloseEvent *event) override;
};

// 表格清理函数
void clearTableCompletely(QTableWidget* tableWidget);

#endif // WIDGET_H
