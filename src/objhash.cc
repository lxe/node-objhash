#include <nan.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.Length() < 1) {
    info.GetReturnValue().Set(Nan::Undefined());
  } else if (info[0]->IsObject()) {
    int hash = info[0]->ToObject()->GetIdentityHash();
    info.GetReturnValue().Set(Nan::New(hash));
  } else {
    info.GetReturnValue().Set(info[0]);
  }
}

void Init(v8::Handle<v8::Object> exports) {
  exports->Set(
    Nan::New("ident").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(Method)->GetFunction()
  );
}

NODE_MODULE(objhash, Init)
