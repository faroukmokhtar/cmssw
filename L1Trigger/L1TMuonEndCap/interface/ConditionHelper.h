#ifndef L1TMuonEndCap_ConditionHelper_h
#define L1TMuonEndCap_ConditionHelper_h

#include "FWCore/Framework/interface/ESHandle.h"

// forwards
namespace edm {
  class Event;
  class EventSetup;
}  // namespace edm

class L1TMuonEndCapParams;
class L1TMuonEndCapForest;

// class declaration
class ConditionHelper {
public:
  ConditionHelper();
  ~ConditionHelper();

  void checkAndUpdateConditions(const edm::Event& iEvent, const edm::EventSetup& iSetup);

  const L1TMuonEndCapParams* getParams() const { return params_.product(); }
  const L1TMuonEndCapForest* getForest() const { return forest_.product(); }

  // EMTF firmware is defined by three numbers:
  //   1. FW version for the core logic
  //   2. pT assignment LUT
  //   3. primitive conversion (PC) LUT
  unsigned int get_fw_version() const;
  unsigned int get_pt_lut_version() const;
  unsigned int get_pc_lut_version() const;
  unsigned int get_pc_lut_version_unchecked() const;

private:
  unsigned long long params_cache_id_;
  unsigned long long forest_cache_id_;

  edm::ESHandle<L1TMuonEndCapParams> params_;
  edm::ESHandle<L1TMuonEndCapForest> forest_;
};

#endif
