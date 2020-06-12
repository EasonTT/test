#include "tutorial.h"

Tutorial::Tutorial(QWidget *parent)
	: QMainWindow(parent)
{
	createCenteralWidget();//创建中央控件

	//创建动作和菜单(顺序不可换！)
	createActions();//创建动作
	createMenus();//创建菜单
	createToolBars();//创建工具栏

	setWindowTitle(QString::fromLocal8Bit("Tutorial"));//设置窗口名称
	setGeometry(300,100,1300,800);//前两个参数为窗口在桌面的位置，后两个为窗口大小
	//setWindowState(Qt::WindowMaximized);//初始全屏显示
}

Tutorial::~Tutorial()
{

}

void Tutorial::createCenteralWidget()
{
	label = new QLabel(QString::fromLocal8Bit("图片"));
	setCentralWidget(label);//把Label控件放在窗体中央
}

//*********************************************
//                  创建Action
//*********************************************
void Tutorial::createActions()
{
	m_pActionOpenFile = new QAction(
		QIcon(".//icon/Open Folder_50px.png"), //图标的相对路径
		QString::fromLocal8Bit("打开"),this); //fromLocal8Bit必不可少，不然中文会乱码

	m_pActionOpenFile->setShortcut(tr("Ctrl+1")); //添加快捷键
	m_pActionOpenFile->setStatusTip(QString::fromLocal8Bit("打开")); //鼠标指针提示

	//m_pActionOpenFile->setEnabled(false);//按键禁用，默认是true

	//信号槽的连接
	connect(m_pActionOpenFile,SIGNAL(triggered(bool)),
		this,SLOT(openFile()));
}

//*********************************************
//                  菜单栏
//   创建了Action后要把Action添加到菜单里面
//*********************************************
void Tutorial::createMenus()
{
	QMenu *menu_file = menuBar()->addMenu(QString::fromLocal8Bit("文件"));
	menu_file->addAction(m_pActionOpenFile);
	//menu_file->addSeparator();//这个是用来增加分隔线的
	//menu_file->addAction(m_pActionExit);//其他的例如退出的按键Action
}

//*********************************************
//                  工具栏
//   创建了Action后要把Action添加到工具栏里面
//*********************************************
void Tutorial::createToolBars()
{
	m_pToolBarOpenFile = addToolBar(QString::fromLocal8Bit("文件"));
	m_pToolBarOpenFile->addAction(m_pActionOpenFile);
	//m_pToolBarOpenFile->setVisible(false);//这种是用来设置是否可见
}

//*********************************************
//                 打开图片文件
//					  槽函数
//*********************************************
void Tutorial::openFile()
{
	QString path = QFileDialog::getOpenFileName(
		this, tr("Open Picture"), ".", tr("Image Files(*.jpg *.png *.bmp)")); 

	//当路径为空
	if(path.isEmpty())
		return;

	QImage img;       
	if(!(img.load(path))) //加载图像        
	{   
		//弹出提示框
		QMessageBox::information(this, tr("Sucess"),tr("Fail!"));           
		return;        
	}        
	//把图片放入label中
	label->setPixmap(QPixmap::fromImage(img.scaled(label->size())));    
}
