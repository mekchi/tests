#version 150

in vec2 frag_uv;

out vec4 out_color;

void main()
{
    float l = length(gl_FragCoord.xy - vec2(400.0, 400.0));

//    out_color = (l < 10.0)
//            ? vec4(.90, .90, .90, 1.0)
//            : vec4(.20, .20, .40, 1.0);

    //out_color = mix(vec4(.90, .90, .90, 1.0), vec4(.20, .20, .40, 1.0), smoothstep(99.0, 101.0, l));

    if (l > 105.0 || l < 95.0)
        out_color = vec4(1.0, 0.0, 0.0, 1.0);
    else
        out_color = vec4(0.0, 0.0, 0.0, 1.0);

//    out_color = vec4(1.0, 0.0, 0.0, 1.0);
}
