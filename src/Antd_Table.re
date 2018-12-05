[@bs.module] external table: ReasonReact.reactClass = "antd/lib/table";

[%bs.raw {|require("antd/lib/table/style")|}];

[@bs.deriving abstract]
type jsProps('a, 'b) = {
  [@bs.optional]
  dataSource: array(Js.t('a)),
  [@bs.optional]
  columns: array('b),
  [@bs.optional]
  prefixCls: string,
  [@bs.optional]
  useFixedHeader: bool,
  [@bs.optional]
  rowSelection: Js.Json.t,
  [@bs.optional]
  className: string,
  [@bs.optional]
  size: string,
  /* TODO */
  /* loading: PropTypes.oneOfType([
       PropTypes.bool,
       PropTypes.object,
     ]), */
  [@bs.optional]
  bordered: bool,
  /* TODO */
  /* onChange: PropTypes.func, */
  [@bs.optional]
  locale: Js.Json.t,
  [@bs.optional]
  dropdownPrefixCls: string,
};

let make =
    (
      ~dataSource=?,
      ~columns=?,
      ~prefixCls=?,
      ~useFixedHeader=?,
      ~rowSelection=?,
      ~className=?,
      ~size=?,
      ~bordered=?,
      ~locale=?,
      ~dropdownPrefixCls=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=table,
    ~props=
      jsProps(
        ~dataSource?,
        ~columns?,
        ~prefixCls?,
        ~useFixedHeader?,
        ~rowSelection?,
        ~className?,
        ~size?,
        ~bordered?,
        ~locale?,
        ~dropdownPrefixCls?,
        (),
      ),
    children,
  );