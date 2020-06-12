#include "tutorial.h"

Tutorial::Tutorial(QWidget *parent)
	: QMainWindow(parent)
{
	createCenteralWidget();//��������ؼ�

	//���������Ͳ˵�(˳�򲻿ɻ���)
	createActions();//��������
	createMenus();//�����˵�
	createToolBars();//����������

	setWindowTitle(QString::fromLocal8Bit("Tutorial"));//���ô�������
	setGeometry(300,100,1300,800);//ǰ��������Ϊ�����������λ�ã�������Ϊ���ڴ�С
	//setWindowState(Qt::WindowMaximized);//��ʼȫ����ʾ
}

Tutorial::~Tutorial()
{

}

void Tutorial::createCenteralWidget()
{
	label = new QLabel(QString::fromLocal8Bit("ͼƬ"));
	setCentralWidget(label);//��Label�ؼ����ڴ�������
}

//*********************************************
//                  ����Action
//*********************************************
void Tutorial::createActions()
{
	m_pActionOpenFile = new QAction(
		QIcon(".//icon/Open Folder_50px.png"), //ͼ������·��
		QString::fromLocal8Bit("��"),this); //fromLocal8Bit�ز����٣���Ȼ���Ļ�����

	m_pActionOpenFile->setShortcut(tr("Ctrl+1")); //��ӿ�ݼ�
	m_pActionOpenFile->setStatusTip(QString::fromLocal8Bit("��")); //���ָ����ʾ

	//m_pActionOpenFile->setEnabled(false);//�������ã�Ĭ����true

	//�źŲ۵�����
	connect(m_pActionOpenFile,SIGNAL(triggered(bool)),
		this,SLOT(openFile()));
}

//*********************************************
//                  �˵���
//   ������Action��Ҫ��Action��ӵ��˵�����
//*********************************************
void Tutorial::createMenus()
{
	QMenu *menu_file = menuBar()->addMenu(QString::fromLocal8Bit("�ļ�"));
	menu_file->addAction(m_pActionOpenFile);
	//menu_file->addSeparator();//������������ӷָ��ߵ�
	//menu_file->addAction(m_pActionExit);//�����������˳��İ���Action
}

//*********************************************
//                  ������
//   ������Action��Ҫ��Action��ӵ�����������
//*********************************************
void Tutorial::createToolBars()
{
	m_pToolBarOpenFile = addToolBar(QString::fromLocal8Bit("�ļ�"));
	m_pToolBarOpenFile->addAction(m_pActionOpenFile);
	//m_pToolBarOpenFile->setVisible(false);//���������������Ƿ�ɼ�
}

//*********************************************
//                 ��ͼƬ�ļ�
//					  �ۺ���
//*********************************************
void Tutorial::openFile()
{
	QString path = QFileDialog::getOpenFileName(
		this, tr("Open Picture"), ".", tr("Image Files(*.jpg *.png *.bmp)")); 

	//��·��Ϊ��
	if(path.isEmpty())
		return;

	QImage img;       
	if(!(img.load(path))) //����ͼ��        
	{   
		//������ʾ��
		QMessageBox::information(this, tr("Sucess"),tr("Fail!"));           
		return;        
	}        
	//��ͼƬ����label��
	label->setPixmap(QPixmap::fromImage(img.scaled(label->size())));    
}
