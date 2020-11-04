#ifndef OBJECTIMAGECORRESPONDENCE_H
#define OBJECTIMAGECORRESPONDENCE_H

#include "image.hpp"
#include "objectmodel.hpp"
#include <QVector3D>
#include <QMatrix3x3>
#include <QString>
#include <QSharedPointer>

//! This class represents a match between an object model and an image, i.e. stores where the object is located on the image and
//! how it is rotated.
class Pose {
public:
    //! Constructor of class ObjectImagePose.
    /*!
     * \brief ObjectImagePose Constructs an ObjectImagePose and assigns the passed values.
     * \param id the ID of the pose
     * \param image the associated image
     * \param objectModel the associated object model
     */
    Pose(QString id, QVector3D position, QMatrix3x3 rotation,
         ImagePtr image, ObjectModelPtr objectModel);

    /*!
     * \brief ObjectImagePose copy constructor for class ObjectImagePose.
     * \param other the pose to copy from
     */
    Pose(const Pose &other);

    /*!
     * \brief getPosition Returns the position of the object on the image. The value z of the position determines the depth,
     * i.e. how big the object is.
     * \return the position of the image
     */
    QVector3D position() const;

    /*!
     * \brief getRotation Returns the rotation of the object on the image.
     * \return the rotation of the image
     */
    QMatrix3x3 rotation() const;

    /*!
     * \brief getImage Returns the image associated with this pose.
     * \return the image associated with this pose
     */
    ImagePtr image() const;

    /*!
     * \brief getObjectModel Returns the object model associated with this pose.
     * \return the object model associated with this pose
     */
    ObjectModelPtr objectModel() const;

    void setPosition(const QVector3D &position);

    void setRotation(const QMatrix3x3 &rotation);
    /*!
     * \brief getID Returns the unique ID of this pose.
     * \return the unique ID of this pose
     */
    QString id() const;

    /*!
     * \brief operator == Returns true if the IDs of the two poses are the same.
     * \param objectImagePose the other pose to check for
     * \return true if the IDs are the same, false otherwise
     */
    bool operator==(const Pose& objectImagePose);

    Pose& operator=(const Pose &other);

private:
    //! The position of the object on the image. The value z is the depth, i.e. how large the object ist.
    QVector3D m_position;
    //! The rotation of the object on the image.
    QMatrix3x3 m_rotation;
    //! The image associated with this corresopndence.
    ImagePtr m_image;
    //! The object model associated with this pose.
    ObjectModelPtr m_objectModel;
    //! The ID of the pose. This is necessary becuase images might contain some objects multiple times.
    QString m_id;

};

typedef QSharedPointer<Pose> PosePtr;

#endif // OBJECTIMAGECORRESPONDENCE_H
