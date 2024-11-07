/*
 * scm.h
 *
 *      Author: Andreas Volz
 */
#ifndef SCM_H_
#define SCM_H_

// Local
#include "Chk.h"
#include "Converter.h"
#include "Storage.h"
#include "Storm.h"

// System
#include <cstring>
#include <vector>
#include <string>
#include <memory>

// Forward declarations
class Hurricane;

/**
 * Map Container
 *
 * The .scm is MPQ encoded and will be decoded to a .chk and then further processed by Chk class
 * It's a wrapper around staredit\\scenario.chk (used by the multimaps)
 */
class Scm : public Converter
{
public:
  Scm(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile, Storage storage);
  virtual ~Scm();

  std::shared_ptr<Chk> chk;

private:
  std::shared_ptr<Storm> m_storm;
  std::string m_scm_path;
};

#endif /* SCM_H_ */
