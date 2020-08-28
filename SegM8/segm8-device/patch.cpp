#pragma XOD require "https://github.com/amperka/SegM8"

{{#global}}
#include "segm8.h"
{{/global}}

struct State {
    uint8_t mem[sizeof(SegM8)];
};

using Type = SegM8*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    State* state = getState(ctx);
    if(isSettingUp()) {
        auto cnt = getValue<input_CNT>(ctx);
        auto cs = getValue<input_CS>(ctx);
        auto d0 = getValue<input_DO>(ctx);
        auto clk = getValue<input_CLK>(ctx);
        Type chain;
        if(d0 == 255 || clk == 255) {
            chain = new (state->mem) SegM8(cs, cnt);
        } else {
            chain = new (state->mem) SegM8(cs, d0, clk, cnt);
        }
        chain->begin();
        emitValue<output_DEV>(ctx, chain);
    }
}
