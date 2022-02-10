import { c as create_ssr_component, v as validate_component } from "../../chunks/index-dbf0e059.js";
import { N as Nav } from "../../chunks/nav-5cf152dc.js";
var about_svelte_svelte_type_style_lang = "";
const css = {
  code: ".content.svelte-1sfqw64{width:100%;max-width:var(--column-width);margin:var(--column-margin-top) auto 0 auto}",
  map: null
};
const About = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  $$result.css.add(css);
  return `${$$result.head += `${$$result.title = `<title>About</title>`, ""}`, ""}

${validate_component(Nav, "Nav").$$render($$result, {}, {}, {})}

<div class="${"flex content svelte-1sfqw64"}"><h1>About this app</h1>
</div>`;
});
export { About as default };
