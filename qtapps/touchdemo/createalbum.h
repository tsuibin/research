#ifndef CREATEALBUM_H
#define CREATEALBUM_H

#include <QWidget>

namespace Ui {
class CreateAlbum;
}

class CreateAlbum : public QWidget
{
    Q_OBJECT
    
public:
    explicit CreateAlbum(QWidget *parent = 0);
    ~CreateAlbum();
    
private:
    Ui::CreateAlbum *ui;
};

#endif // CREATEALBUM_H
