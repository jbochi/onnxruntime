#pragma once
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include <memory>

namespace onnxruntime {

class SessionState;
class ExecutionFrame;
class OpKernelContextInternal;
class OpKernel;
class SessionScope;
class SessionScopeImpl;
class KernelScopeImpl;

class SessionScope {
 public:
  friend class KernelScopeImpl;
  SessionScope(const SessionState&, const ExecutionFrame&);
  ~SessionScope() = default;

 private:
  std::unique_ptr<SessionScopeImpl> impl_;
};

class KernelScope {
 public:
  KernelScope(OpKernelContextInternal&,
              const OpKernel&,
              SessionScope&);
  ~KernelScope() = default;

 private:
  std::unique_ptr<KernelScopeImpl> impl_;
};

}  // namespace onnxruntime