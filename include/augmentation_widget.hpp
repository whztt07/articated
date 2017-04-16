// augmentation_widget.h

#ifndef AUGMENTATION_WIDGET_HPP
#define AUGMENTATION_WIDGET_HPP

#include <QMatrix4x4>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QString>
#include <QVector2D>
#include <QVector3D>

#include "model_loader.hpp"
#include "operators.hpp"

class augmentation_widget : public QOpenGLWidget, protected QOpenGLExtraFunctions {
    Q_OBJECT
    public:
    augmentation_widget (QWidget* parent = 0);
    ~augmentation_widget ();

    void initializeGL ();
    void resizeGL (int w, int h);
    void paintGL ();

    QSize minimumSizeHint () const;
    QSize sizeHint () const;

    public slots:
    bool loadObject (const QString& path);
    void setBackground (image_t image);
    void setScale (const float factor);
    void setXPosition (const float location);
    void setYPosition (const float location);
    void setZRotation (const GLfloat);
    void setXRotation (const GLfloat);
    void setYRotation (const GLfloat);

    signals:

    private:
    bool upload_to_gpu (const std::vector<float>& model_interleafed);
    void draw_background ();

    model_obj _object;
    float _scale_factor;
    float _x_pos;
    float _y_pos;
    QMatrix4x4 _mat_x_rot;
    QMatrix4x4 _mat_y_rot;
    QMatrix4x4 _mat_z_rot;
    QMatrix4x4 _mat_projection;
    GLuint _texture_background;
    QOpenGLShaderProgram _program;
};

#endif // AUGMENTATION_WIDGET_HPP
