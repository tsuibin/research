#ifndef ALBUMPREVIEW_H
#define ALBUMPREVIEW_H

#include <QWidget>

namespace Ui {
class AlbumPreview;
}

class AlbumPreview : public QWidget
{
    Q_OBJECT
    
public:
    explicit AlbumPreview(QWidget *parent = 0);
    ~AlbumPreview();
    
private:
    Ui::AlbumPreview *ui;
};

#endif // ALBUMPREVIEW_H
