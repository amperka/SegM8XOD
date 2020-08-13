
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto ext = getValue<input_DEV>(ctx);

    if (isSettingUp())
        emitValue<output_DEVU0027>(ctx, ext);

    if(isInputDirty<input_DO>(ctx)) {
        ext->chain->clear();
        emitValue<output_DONE>(ctx, true);
    }
}
