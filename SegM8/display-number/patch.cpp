
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto chain = getValue<input_DEV>(ctx);
    auto num = getValue<input_NUM>(ctx);
    auto position = getValue<input_POS>(ctx);
    auto width = getValue<input_WDTH>(ctx);
    auto precission = getValue<input_PREC>(ctx);
    auto radix = getValue<input_RDX>(ctx);
    auto leadzeros = getValue<input_LEAD0>(ctx);
    auto toleft = getValue<input_LEFT>(ctx);

    if (isSettingUp())
        emitValue<output_DEVU0027>(ctx, chain);

    if(isInputDirty<input_DO>(ctx)) {
        if(precission == 0) { // it is integer, not float
            if(radix == 10) {
                chain->display((int32_t)num, position, width, (toleft ? SEGM8_ALIGN_LEFT : 0) | (leadzeros ? SEGM8_PAD_ZEROS : 0));
            } else if(radix == 16) {
                chain->display((uint32_t)num, position, width, (toleft ? SEGM8_ALIGN_LEFT : 0) | (leadzeros ? SEGM8_PAD_ZEROS : 0) | SEGM8_RADIX_16);
            } else { // other radixes not supported - error
                chain->display("ERROR", position, width, SEGM8_ALIGN_LEFT);
            }
        } else { // it is float
            chain->display((double)num, position, width, precission, (toleft ? SEGM8_ALIGN_LEFT : 0) | (leadzeros ? SEGM8_PAD_ZEROS : 0));
        }
        emitValue<output_DONE>(ctx, true);
    }
}
