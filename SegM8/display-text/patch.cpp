
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto ext = getValue<input_DEV>(ctx);
    auto text = getValue<input_TEXT>(ctx);
    auto position = getValue<input_POS>(ctx);
    auto width = getValue<input_WDTH>(ctx);

    if (isSettingUp())
        emitValue<output_DEVU0027>(ctx, ext);

    if(isInputDirty<input_DO>(ctx)) {
        char* buf = new char(length(text)+1);
        dump(text, buf);
        ext->chain->display(buf, position, width, SEGM8_ALIGN_LEFT);
        delete buf;
        emitValue<output_DONE>(ctx, true);
    }
}
