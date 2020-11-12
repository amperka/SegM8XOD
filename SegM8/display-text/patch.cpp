
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto chain = getValue<input_DEV>(ctx);
    auto text = getValue<input_TEXT>(ctx);
    auto position = getValue<input_POS>(ctx);
    auto width = getValue<input_W>(ctx);

    if (isSettingUp())
        emitValue<output_DEVU0027>(ctx, chain);

    if(isInputDirty<input_UPD>(ctx)) {
        char* buf = new char(length(text)+1);
        dump(text, buf);
        for(uint8_t i = 0; i < width; i++) chain->writeSegments( 0, position + i); // clear field, put spaces
        chain->display(buf, position, width, SEGM8_ALIGN_LEFT);
        delete buf;
        emitValue<output_DONE>(ctx, true);
    }
}
