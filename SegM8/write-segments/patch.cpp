
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto chain = getValue<input_DEV>(ctx);
    auto mask = getValue<input_TMPL>(ctx);
    auto position = getValue<input_POS>(ctx);

    if (isSettingUp())
        emitValue<output_DEVU0027>(ctx, chain);

    if(isInputDirty<input_DO>(ctx)) {
        chain->writeSegments(mask, position);
        emitValue<output_DONE>(ctx, true);
    }
}
