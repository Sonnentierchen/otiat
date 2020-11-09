#include "galleryobjectmodels.hpp"
#include "view/gallery/galleryobjectmodelmodel.hpp"
#include "ui_gallery.h"

GalleryObjectModels::GalleryObjectModels(QWidget *parent) : Gallery(parent) {

}

void GalleryObjectModels::selectObjectModelByID(const ObjectModel &objectModel, bool emitSignals) {
    ignoreSelectionChanges = !emitSignals;
    GalleryObjectModelModel *model = dynamic_cast<GalleryObjectModelModel*>(ui->listView->model());
    QModelIndex index = model->indexOfObjectModel(objectModel);
    if (index.isValid()) {
        ui->listView->selectionModel()->select(index, QItemSelectionModel::ClearAndSelect);
        QRect test = ui->listView->visualRect(index);
        qDebug() << test;
        ui->listView->scrollTo(index);
    } else {
        ui->listView->selectionModel()->clearSelection();
    }
}
