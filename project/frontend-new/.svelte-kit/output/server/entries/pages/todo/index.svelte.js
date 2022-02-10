import { c as create_ssr_component, v as validate_component } from "../../../chunks/index-dbf0e059.js";
import { N as Nav } from "../../../chunks/nav-5cf152dc.js";
import { F as Footer } from "../../../chunks/footer-88567eb4.js";
async function load({ session }) {
  console.log("todo session", session);
  return { props: { session } };
}
const Todo = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  return `${$$result.head += `${$$result.title = `<title>Home</title>`, ""}`, ""}

<div class="${"min-h-screen flex flex-col"}">${validate_component(Nav, "Nav").$$render($$result, {}, {}, {})}
	<section class="${"flex flex-col flex-1 overflow-hidden min-h-max"}"><div class="${"flex flex-1 overflow-hidden"}">todo</div></section>
	${validate_component(Footer, "Footer").$$render($$result, {}, {}, {})}</div>`;
});
export { Todo as default, load };
