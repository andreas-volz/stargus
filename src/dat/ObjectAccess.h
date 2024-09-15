/*
 * ObjectAccess.h
 *
 *      Author: Andreas Volz
 */

#ifndef OBJECTACCESS_H
#define OBJECTACCESS_H

// project
#include "DataHub.h"

namespace dat
{

class ObjectAccess
{
public:
  ObjectAccess(DataHub &datahub, unsigned int id) : mDatahub(datahub), mId(id) {
    mGenerateObjects = true;
  }
  virtual ~ObjectAccess() {}

  virtual unsigned int id() {return mId;}

  /**
   * @param generateObjects is able to hold this for the generating API. It does nothing with the object itself.
   *        In case one calls *_obj() it still works as expected.
   */
  virtual void set_generate_objects(bool generateObjects) {mGenerateObjects = generateObjects;}

  /**
   * @returns the information if a calling API should also call *_obj() functions. This is helpfull for the JSON generator.
   */
  virtual bool get_generate_objects() {return mGenerateObjects;}

protected:
  DataHub &mDatahub;
  unsigned int mId;
  bool mGenerateObjects;
};

} /* namespace dat */

#endif /* OBJECTACCESS_H */
