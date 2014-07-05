#include <nan.h>

using namespace v8;

NAN_METHOD(Ident) {
  NanScope();
  if (args.Length() < 1) {
    NanReturnUndefined();
  } else if (args[0]->IsObject()) {
    int hash = args[0]->ToObject()->GetIdentityHash();
    NanReturnValue(NanNew<Number>(hash));
  } else {
    NanReturnValue(args[0]);
  }
}

void Init(Handle<Object> exports) {
  exports->Set(
    NanNew("ident"), 
    NanNew<FunctionTemplate>(Ident)->GetFunction()
  );
}

NODE_MODULE(objhash, Init)
