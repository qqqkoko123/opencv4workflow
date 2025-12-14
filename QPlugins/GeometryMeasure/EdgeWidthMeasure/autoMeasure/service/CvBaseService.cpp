/**
 * Created by Jiajun Chen on 2022/1/6.
 */

#include "CvBaseService.h"

#include <utility>
#include <qstring.h>

CvBaseService::CvBaseService(QString name) :
        name(std::move(name)),
        repoLink("https://github.com/opencv/opencv"),
        iconSource("qrc:/assets/image/opencv.png") {}