
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto chain = getValue<input_DEV>(ctx);

    if (isSettingUp())
        emitValue<output_DEVU0027>(ctx, chain);

    if(isInputDirty<input_DO>(ctx)) {
        chain->clear();
        emitValue<output_DONE>(ctx, true);
    }
}
