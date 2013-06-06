#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> Ident(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1) {
    return scope.Close(Undefined());
  }

  if (args[0]->IsObject()) {
    return scope.Close(v8::Integer::New(
      args[0]->ToObject()->GetIdentityHash()));
  }

  return scope.Close(args[0]);
}

void Init(Handle<Object> exports, Handle<Object> module) {
  module->Set(String::NewSymbol("exports"),
      FunctionTemplate::New(Ident)->GetFunction());
}

NODE_MODULE(objhash, Init)
